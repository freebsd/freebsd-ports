# Build Makefile for lang/pypy
# $FreeBSD$

# Required environment variables
# - DISTVERSION
# - PYTHON_CMD
# - PYPY_INST
# - PYPY_${inst}_NAME
# - PYPY_${inst}_OBJSPACE_ARGS
# - PYPY_${inst}_OPT
# - PYPY_${inst}_TRANSLATE_ARGS
# - WRKSRC

CP?=		cp
ECHO?=		echo
MKDIR?=		mkdir
RM?=		rm
SED?=		sed
SETENV?=	env
TOUCH?=		touch

REINPLACE_CMD?=	${SED} -i~

BUILDDIR=	usession-release-${DISTVERSION}.x-0

.for inst in ${PYPY_INST}

${PYPY_${inst}_NAME}: build_${PYPY_${inst}_NAME}/${BUILDDIR}/testing_1/pypy-c
	${CP} build_${PYPY_${inst}_NAME}/${BUILDDIR}/testing_1/pypy-c \
		${PYPY_${inst}_NAME}

.done_translate_${PYPY_${inst}_NAME}:
	${RM} -rf build_${PYPY_${inst}_NAME}
	${MKDIR} build_${PYPY_${inst}_NAME}
	(cd ${WRKSRC}/pypy/goal; \
		/usr/bin/time -l ${SETENV} TMPDIR=${.CURDIR}/build_${PYPY_${inst}_NAME} \
		${PYTHON_CMD} ../../rpython/bin/rpython --source ${PYPY_${inst}_TRANSLATE_ARGS} -O${PYPY_${inst}_OPT} \
			targetpypystandalone.py ${PYPY_${inst}_OBJSPACE_ARGS} )
	${TOUCH} .done_translate_${PYPY_${inst}_NAME}

build_${PYPY_${inst}_NAME}/${BUILDDIR}/testing_1/pypy-c: .done_translate_${PYPY_${inst}_NAME}
	${REINPLACE_CMD} -e 's|^%.o: %.c$$|.c.o:|g' build_${PYPY_${inst}_NAME}/${BUILDDIR}/testing_1/Makefile
	/usr/bin/time -l ${MAKE} -C build_${PYPY_${inst}_NAME}/${BUILDDIR}/testing_1 pypy-c
.endfor
