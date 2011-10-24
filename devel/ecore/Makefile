# New ports collection makefile for:	ecore
# Date created:		22 September 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ecore
DISTVERSION=	1.0.1
PORTEPOCH=	2
CATEGORIES=	devel enlightenment
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (meta port)

NO_BUILD=	yes
USE_EFL=	ecore

ECORE_MODULES=	con evas file imf imf_evas input input_evas ipc sdl x11
ECORE_sdl_off=	yes

.for NODE in ${ECORE_MODULES}
OPTIONS+=	${NODE:U} "Install ${NODE} ecore module"
. if !defined(ECORE_${NODE}_off)
OPTIONS+=	on
. else
OPTIONS+=	off
. endif
.endfor

.include <bsd.port.pre.mk>

.for NODE in ${ECORE_MODULES}
. if !defined(ECORE_${NODE}_off)
.  if !defined(WITHOUT_${NODE:U})
USE_EFL_ECORE+=	${NODE}
.  endif
. else
.  if defined(WITH_${NODE:U})
USE_EFL_ECORE+=	${NODE}
.  endif
. endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
