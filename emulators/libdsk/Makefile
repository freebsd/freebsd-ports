# Created by: pixel
# $FreeBSD$

PORTNAME=	libdsk
PORTVERSION=	1.4.2
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.info/Unix/LibDsk/

MAINTAINER=	pixel@hugbox.org
COMMENT=	Enables access to disks and disk images; also via serial line

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	apridisk.html cfi.html libdsk.pdf libdsk.txt \
		libdskrc.sample protocol.txt README TODO

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
