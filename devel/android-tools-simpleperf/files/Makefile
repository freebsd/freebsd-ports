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
SRCS+=	environment_fake.cpp
SRCS+=	event_attr.cpp
SRCS+=	event_type.cpp
SRCS+=	main.cpp
SRCS+=	perf_regs.cpp
SRCS+=	read_elf.cpp
SRCS+=	record.cpp
SRCS+=	record_file_reader.cpp
SRCS+=	sample_tree.cpp
SRCS+=	thread_tree.cpp
SRCS+=	utils.cpp

TEST_SRCS+=	command_test.cpp
TEST_SRCS+=	gtest_main.cpp
TEST_SRCS+=	record_test.cpp
TEST_SRCS+=	sample_tree_test.cpp

# required by simpleperf
.PATH: ${.CURDIR}/../base
SRCS+=	file.cpp
SRCS+=	logging.cpp
SRCS+=	stringprintf.cpp
SRCS+=	strings.cpp

# required by base
.PATH:	${.CURDIR}/../liblog
SRCS+=	fake_log_device.c
SRCS+=	logd_write.c
CFLAGS.logd_write.c+=	-DFAKE_LOG_DEVICE=1

# required by base
.PATH: ${.CURDIR}/../libcutils
SRCS+= threads.c

CFLAGS+=-D_WITH_GETLINE
CFLAGS+=-DUSE_BIONIC_UAPI_HEADERS
CFLAGS+=-I${.CURDIR}/darwin_support
CFLAGS+=-I${.CURDIR}/../include
CFLAGS+=-I${.CURDIR}/../base/include
CFLAGS+=-I${.CURDIR}/../bionic/libc/kernel
CFLAGS+=$$(${LLVM_CONFIG} --cppflags)
CFLAGS+=${CFLAGS.${.IMPSRC:T}}

CXXFLAGS+=-std=gnu++11
CXXFLAGS+=${CFLAGS:N-std*}

TEST_CFLAGS+=	$$(${GTEST_CONFIG} --cppflags)
.for f in ${TEST_SRCS}
CFLAGS.${f}+=	${TEST_CFLAGS}
.endfor

LDADD+=		$$(${LLVM_CONFIG} --system-libs --libs --ldflags)
TEST_LDADD+=	$$(${GTEST_CONFIG} --libs --ldflags)

LLVM_CONFIG?=	llvm-config
GTEST_CONFIG?=	gtest-config

simpleperf_unit_test: ${SRCS:R:S/$/.o/:Nmain.o} ${TEST_SRCS:R:S/$/.o/}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o $@ $> ${LDADD} ${TEST_LDADD}

.include <bsd.prog.mk>
