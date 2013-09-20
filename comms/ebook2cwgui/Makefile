# $FreeBSD$

PORTNAME=	ebook2cwgui
PORTVERSION=	0.1.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/ebook2cw/ \
		http://distfiles.bsdjunk.com/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	WxWidgets front end for ebooks2cw

RUN_DEPENDS=	ebook2cw:${PORTSDIR}/comms/ebook2cw

MAN1=		ebook2cwgui.1

USE_WX=	yes

PLIST_FILES=	bin/ebook2cwgui
PORTDOCS=	*

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG:S,${PREFIX}/bin/,,}|g' \
	     ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		-e 's|g++|${CXX}|g' \
	     ${WRKSRC}/Makefile

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/ebook2cwgui ${PREFIX}/bin/ebook2cwgui
	@${INSTALL_DATA} ${WRKSRC}/ebook2cwgui.1 ${MANPREFIX}/man/man1
.if     !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for 	f in README COPYING ChangeLog
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}/$f
.endfor
.endif

.include <bsd.port.mk>
