# New ports collection makefile for:   merkaartor
# Date created:        9 January 2009
# Whom:                slaven@rezic.de
#
# $FreeBSD$
#

PORTNAME=	merkaartor
PORTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.merkaartor.org/downloads/source/

MAINTAINER=	slaven@rezic.de
COMMENT=	An openstreetmap mapping program

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2

USE_BZIP2=	yes

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build linguist_build \
		gui network svg webkit xml imageformats

MAN1=		merkaartor.1

HAS_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/lrelease|&-qt4|' \
		${WRKSRC}/Merkaartor.pro

# Don't ask. If the compiler_TSQM_make_all target is not called before
# calling qmake-qt4, then the install_translations target won't show
# up in the Makefile.
do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX}
	cd ${WRKSRC} && ${MAKE} compiler_TSQM_make_all
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/merkaartor.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
