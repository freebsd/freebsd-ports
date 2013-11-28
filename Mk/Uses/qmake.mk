# $FreeBSD$
#
# Provide support for qmake based projects
#
# MAINTAINER: kde@FreeBSD.org
#
# Feature:		qmake
# Usage:		USES=qmake or USES=qmake:ARGS
#			Must be used along with	'USE_QT4='
# Valid ARGS:		norecursive
# ARGS description:
# norecursive		Don't pass -recursive argument to qmake binary
#
#
# Variables for ports:
# QMAKE_ENV		- Environment passed to qmake.
#			Default: ${CONFIGURE_ENV}
# QMAKE_ARGS		- Arguments passed to qmake.
#			Default: see below
# QMAKE_SOURCE_PATH	- Path to qmake project files.
#			Default: empty (autodetect)
#
# User defined variables:
# QMAKE_VERBOSE		- Enable verbose configure output.
#

.if !defined(_INCLUDE_USES_QMAKE_MK)
_INCLUDE_USES_QMAKE_MK=	yes

.if !defined(NO_STAGE)
DESTDIRNAME=	INSTALL_ROOT
.endif

.if defined(qmake_ARGS)
. if ${qmake_ARGS} == "norecursive"
QMAKE_NORECURSIVE=	yes
. else
IGNORE=	Incorrect 'USES+= qmake' usage: argument '${qmake_ARGS}' is not recognized
. endif
.endif

.if !defined(USE_QT4)
IGNORE=	'USES+= qmake' must be accompanied with 'USE_QT4= #'
.endif

USE_QT4+=	qmake_build

.if !defined(QMAKE_NORECURSIVE)
QMAKE_ARGS+=	-recursive
.endif

.if defined(QMAKE_VERBOSE)
QMAKE_ARGS+=	-d
.endif

QMAKE_SOURCE_PATH?=	${QMAKE_PRO}

.if !target(do-configure)
do-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} ${QMAKE_SOURCE_PATH}
.endif

.endif #!defined(_INCLUDE_USES_QMAKE_MK)
