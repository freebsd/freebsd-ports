# New ports collection makefile for:   	flPhoto
# Date created:				24 November, 2003
# Whom:                			johan
#
# $FreeBSD$
#

PORTNAME=	flphoto
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fltk
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A basic image management and display program

LIB_DEPENDS=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		flphoto.1
MAN5=		album.5

post-patch:
	@${REINPLACE_CMD} -e 's|@OPTIM@|-DHAVE_CONFIG_H|g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flphoto ${PREFIX}/bin/flphoto
	${INSTALL_MAN} ${WRKSRC}/doc/flphoto.man ${MANPREFIX}/man/man1/flphoto.1
	${INSTALL_MAN} ${WRKSRC}/doc/album.man ${MAN5PREFIX}/man/man5/album.5
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.for lang in de en_CA en_GB es fr it nl pt
	@${MKDIR} ${PREFIX}/share/locale/${lang}
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.po \
		${PREFIX}/share/locale/${lang}/flphoto_${lang}
.endfor

.include <bsd.port.mk>
