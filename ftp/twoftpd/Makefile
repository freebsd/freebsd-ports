# Created by: Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
# $FreeBSD$

PORTNAME=	twoftpd
PORTVERSION=	1.42
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/${PORTNAME}/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, secure, efficient FTP server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/bg-installer:devel/bglibs
LIB_DEPENDS=	libcvm-v2client.so:security/cvm

USES=		localbase

BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
BGLIBS_INCLUDE=	${LOCALBASE}/include/bglibs

PORTDOCS=	NEWS README TODO
PLIST_FILES=	bin/twoftpd-anon bin/twoftpd-anon-conf \
		bin/twoftpd-auth bin/twoftpd-bind-port \
		bin/twoftpd-conf bin/twoftpd-drop \
		bin/twoftpd-switch bin/twoftpd-xfer \
		man/man1/twoftpd-auth.1.gz man/man1/twoftpd-switch.1.gz \
		man/man1/twoftpd-xfer.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,timezone,tm.tm_gmtoff,' ${WRKSRC}/statmod.c

do-configure:
	@${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/conf-bin
	@${ECHO_CMD} "${MANPREFIX}/man" > ${WRKSRC}/conf-man
	@${ECHO_CMD} "${CC} ${CFLAGS} ${CPPFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${BGLIBS_INCLUDE}" > ${WRKSRC}/conf-bgincs
	@${ECHO_CMD} "${BGLIBS_LIB}" > ${WRKSRC}/conf-bglibs

do-install:
.for f in twoftpd-anon twoftpd-anon-conf twoftpd-auth twoftpd-bind-port \
	twoftpd-conf twoftpd-drop twoftpd-switch twoftpd-xfer
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for f in twoftpd-auth.1 twoftpd-switch.1 twoftpd-xfer.1
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${MAN1PREFIX}/man/man1/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
