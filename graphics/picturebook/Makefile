# Created by: Takanori Watanabe <takawata@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picturebook
PORTVERSION=	20010422
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://samba.org/picturebook/
DISTNAME=	capture

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SONY VAIO camera capture utility

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GNOME=	imlib
USES=		tar:tgz

PLIST_FILES=	bin/capture sbin/setbrightness sbin/vaiobat
PORTDOCS=	README README.FreeBSD

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} -o setbrightness setbrightness.c; \
	${CC} ${CFLAGS} -o vaiobat vaiobat.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/capture ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} setbrightness vaiobat \
		${STAGEDIR}${PREFIX}/sbin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PATCHDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
