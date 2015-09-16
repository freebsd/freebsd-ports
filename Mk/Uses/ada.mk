# $FreeBSD$
#
# Establish Ada-capable compiler as a build dependency
# To change default compiler, define ADA_DEFAULT in make.conf to 5
# Note that gcc47-aux is being removed soon, so 47 is not a legal default
#
# Feature:      ada
# Usage:        USES=ada
# Valid ARGS:   49, 5, run
#
# MAINTAINER: marino@FreeBSD.org

.if !defined(_INCLUDE_USES_ADA_MK)
_INCLUDE_USES_ADA_MK=    yes

CC= ada

. if ${ada_ARGS:M49}
ADAXX=	gcc
. elif ${ada_ARGS:M5}
ADAXX=	gcc5
. else
.  if defined(ADA_DEFAULT) && ${ADA_DEFAULT} == 49
ADAXX=	gcc
.  else
ADAXX=	gcc5
.  endif
. endif

. if ${ada_ARGS:Mrun}
RUN_DEPENDS+=	${LOCALBASE}/${ADAXX}-aux/bin/ada:${PORTSDIR}/lang/${ADAXX}-aux
. endif

BUILD_DEPENDS+=	${LOCALBASE}/${ADAXX}-aux/bin/ada:${PORTSDIR}/lang/${ADAXX}-aux
MAKE_ENV+=	PATH=${LOCALBASE}/${ADAXX}-aux/bin:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat
CONFIGURE_ENV+=	PATH=${LOCALBASE}/${ADAXX}-aux/bin:${PATH} \
		ADA_PROJECT_PATH=${LOCALBASE}/lib/gnat

.endif
