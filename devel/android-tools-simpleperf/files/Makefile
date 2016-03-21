# $FreeBSD$

PROG_CXX=simpleperf
NO_MAN=
BINDIR?=/usr/bin

SRCS+=	callchain.cpp
SRCS+=	cmd_dumprecord.cpp
SRCS+=	cmd_help.cpp
SRCS+=	cmd_report.cpp
SRCS+=	command.cpp
SRCS+=	dso.cpp
SRCS+=	event_attr.cpp
SRCS+=	event_type.cpp
SRCS+=	main.cpp
SRCS+=	perf_regs.cpp
SRCS+=	read_apk.cpp
SRCS+=	read_elf.cpp
SRCS+=	record.cpp
SRCS+=	record_file_reader.cpp
SRCS+=	sample_tree.cpp
SRCS+=	thread_tree.cpp
SRCS+=	utils.cpp

TEST_SRCS+=	cmd_report_test.cpp
TEST_SRCS+=	command_test.cpp
TEST_SRCS+=	gtest_main.cpp
TEST_SRCS+=	read_apk_test.cpp
TEST_SRCS+=	read_elf_test.cpp
TEST_SRCS+=	record_test.cpp
TEST_SRCS+=	sample_tree_test.cpp

.PATH: ${.CURDIR}/nonlinux_support
SRCS+=	nonlinux_support.cpp

# required by simpleperf
.PATH: ${.CURDIR}/../base
SRCS+=	file.cpp
SRCS+=	logging.cpp
SRCS+=	stringprintf.cpp
SRCS+=	strings.cpp
TEST_SRCS+= file_test.cpp
TEST_SRCS+= logging_test.cpp
TEST_SRCS+= stringprintf_test.cpp
TEST_SRCS+= strings_test.cpp
TEST_SRCS+= test_utils.cpp

# required by base
.PATH:	${.CURDIR}/../liblog
SRCS+=	fake_log_device.c
SRCS+=	logd_write.c
CPPFLAGS.logd_write.c+=	-DFAKE_LOG_DEVICE=1

# required by base
.PATH: ${.CURDIR}/../libcutils
SRCS+= threads.c

# required by libziparchive
.PATH: ${.CURDIR}/../libutils
SRCS+=	FileMap.cpp

# required by simpleperf
.PATH:	${.CURDIR}/../libziparchive
SRCS+=	zip_archive.cc

# required by simpleperf
.PATH: ${.CURDIR}/../lzma/C
SRCS+=	7zCrc.c
SRCS+=	7zCrcOpt.c
SRCS+=	Bra86.c
SRCS+=	Bra.c
SRCS+=	BraIA64.c
SRCS+=	CpuArch.c
SRCS+=	Delta.c
SRCS+=	Lzma2Dec.c
SRCS+=	LzmaDec.c
SRCS+=	Sha256.c
SRCS+=	Xz.c
SRCS+=	XzCrc64.c
SRCS+=	XzCrc64Opt.c
SRCS+=	XzDec.c

CPPFLAGS+=	-D_7ZIP_ST
CPPFLAGS+=	-D_WITH_GETLINE
CPPFLAGS+=	-DUSE_BIONIC_UAPI_HEADERS
CPPFLAGS+=	-Doff64_t=off_t
CPPFLAGS+=	-Dftruncate64=ftruncate
CPPFLAGS+=	-Dlseek64=lseek
CPPFLAGS+=	-Dmmap64=mmap
CPPFLAGS+=	-Dpread64=pread
CPPFLAGS+=	-I${.CURDIR}
CPPFLAGS+=	-I${.CURDIR}/nonlinux_support/include
CPPFLAGS+=	-I${.CURDIR}/../include
CPPFLAGS+=	-I${.CURDIR}/../base/include
CPPFLAGS+=	-I${.CURDIR}/../bionic/libc/kernel
CPPFLAGS+=	-I${.CURDIR}/../lzma/C
CPPFLAGS+=	$$(${LLVM_CONFIG} --cppflags)
CPPFLAGS+=	${CPPFLAGS.${.IMPSRC:T}}
CXXFLAGS+=	-std=gnu++11

.ifndef COMPILE.c
CFLAGS+=	${CPPFLAGS}
CXXFLAGS+=	${CPPFLAGS}
.endif

TEST_CPPFLAGS+=	$$(${GTEST_CONFIG} --cppflags)
.for f in ${TEST_SRCS}
CPPFLAGS.${f}+=	${TEST_CPPFLAGS}
.endfor

LDADD+=		$$(${LLVM_CONFIG} --system-libs --libs --ldflags)
TEST_LDADD+=	$$(${GTEST_CONFIG} --libs --ldflags)

TEST_OBJS+=	${TEST_SRCS:R:S/$/.o/}
CLEANFILES+=	${PROG}_test ${TEST_OBJS}

LLVM_CONFIG?=	llvm-config
GTEST_CONFIG?=	gtest-config

.include <bsd.prog.mk>

test: ${PROG}_test
	@for f in ${.ALLSRC}; do ./$$f -t ${.CURDIR}/testdata; done

${PROG}_test: ${OBJS:Nmain.o} ${TEST_OBJS}
	${CXX} ${CPPFLAGS} ${CXXFLAGS} ${LDFLAGS} -o $@ $> ${LDADD} ${TEST_LDADD}
