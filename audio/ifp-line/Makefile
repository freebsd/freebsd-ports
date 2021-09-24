# Created by: riggs

PORTNAME=	ifp-line
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/ifp-driver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line interface to iRiver music players

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandoned upstream, no new release since 2005
EXPIRATION_DATE=2021-12-31

USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBUSB_LIBS=-lusb
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/ifp man/man1/ifp.1.gz
PORTDOCS=	NEWS README TIPS nonroot.sh

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifp.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
