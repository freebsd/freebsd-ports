# Created by: Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
# $FreeBSD$

PORTNAME=	twoftpd
PORTVERSION=	1.42
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple, secure, efficient FTP server

BUILD_DEPENDS=	${LOCALBASE}/bin/bg-installer:${PORTSDIR}/devel/bglibs
LIB_DEPENDS=	cvm-v2client:${PORTSDIR}/security/cvm

#LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS


CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
BGLIBS_INCLUDE=	${LOCALBASE}/include/bglibs

MAN1=		twoftpd-auth.1 twoftpd-switch.1 twoftpd-xfer.1
PORTDOCS=	NEWS README TODO
PLIST_FILES=	bin/twoftpd-anon bin/twoftpd-anon-conf \
		bin/twoftpd-auth bin/twoftpd-bind-port \
		bin/twoftpd-conf bin/twoftpd-drop \
		bin/twoftpd-switch bin/twoftpd-xfer

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,timezone,tm.tm_gmtoff,' ${WRKSRC}/statmod.c

do-configure:
	@${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/conf-bin
	@${ECHO_CMD} "${MANPREFIX}/man" > ${WRKSRC}/conf-man
	@${ECHO_CMD} "${CC} ${CFLAGS} ${CPPFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${BGLIBS_INCLUDE}" > ${WRKSRC}/conf-bgincs
	@${ECHO_CMD} "${BGLIBS_LIB}" > ${WRKSRC}/conf-bglibs

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
