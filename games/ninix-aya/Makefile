# New ports collection makefile for:	ninix-aya
# Date created:				6 Dec 2003
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	ninix-aya
PORTVERSION=	3.9.9a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ninix-aya/44636
DISTNAME=	ninix-aya-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Ninix-aya is a compatible with desktop mascot program "Ukagaka"

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		lha:${PORTSDIR}/archivers/lha \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

PYVERSION=	${PYTHON_VERSION:S/^python//}
.if defined(PYTHON_VERSION) && ${PYVERSION:S/.//} < 24
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec
.endif # defined(PYVERSION) && ${PYVERSION:S/.//} < 24

USE_PYTHON=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
