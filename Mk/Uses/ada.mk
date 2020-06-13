# $FreeBSD$
#
# Establish Ada-capable compiler as a build dependency
# To change default compiler, define ADA_DEFAULT in make.conf
#
# Feature:      ada
# Usage:        USES=ada
# Valid ARGS:   run
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

CC=	ada
ADAXX=	gcc6	# framework default

. if ${ada_ARGS:Mrun}
RUN_DEPENDS+=	${LOCALBASE}/${ADAXX}-aux/bin/ada:lang/${ADAXX}-aux
. endif

BUILD_DEPENDS+=	${LOCALBASE}/${ADAXX}-aux/bin/ada:lang/${ADAXX}-aux
MAKE_ENV+=	PATH=${LOCALBASE}/${ADAXX}-aux/bin:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat
CONFIGURE_ENV+=	PATH=${LOCALBASE}/${ADAXX}-aux/bin:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

.endif
