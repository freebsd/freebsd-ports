# Created by: David K. Gerry
# $FreeBSD$

PORTNAME=	eflite
PORTVERSION=	0.4.1
CATEGORIES=	accessibility
MASTER_SITES=	SF

MAINTAINER=	David.K.Gerry@GMail.com
COMMENT=	Speech server for Festival Lite used by yasr and Emacspeak

BUILD_DEPENDS=	flite:audio/flite
RUN_DEPENDS=	flite:audio/flite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
GNU_CONFIGURE=	yes
ALL_TARGET=	eflite

CONFIGURE_ARGS+=	--with-audio=freebsd
.if defined(FL_LANG)
CONFIGURE_ARGS+=	--with-lang=${FL_LANG}
.endif
.if defined(FL_LEX)
CONFIGURE_ARGS+=	--with-lex=${FL_LEX}
.endif
.if defined(FL_VOX)
CONFIGURE_ARGS+=	--with-vox=${FL_VOX}
.else
CONFIGURE_ARGS+=	--with-vox=cmu_us_kal16
.endif

CONFIGURE_ENV+=	flite_dir=${LOCALBASE}

PLIST_FILES=	bin/eflite
PORTDOCS=	AUTHORS CREDITS ChangeLog INSTALL README

OPTIONS_DEFINE=	DOCS

pre-fetch:
.ifdef!(FL_LANG || FL_LEX || FL_VOX)
	@${ECHO_MSG} "===>  You can set FL_LANG, FL_LEX and/or FL_VOX"
	@${ECHO_MSG} "      to link the appropriate libflite_* libraries"
	@${ECHO_MSG} "      (i.e. \"make FL_VOX=cmu_us_kal\".)"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/es\.conf|${PREFIX}/etc/es.conf|' ${WRKSRC}/es.c
	@${REINPLACE_CMD} -e 's|/etc/es\.conf|${PREFIX}/etc/es.conf|;s|sockname|socketfile|g' ${WRKSRC}/INSTALL

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/es.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
