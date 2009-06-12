# New ports collection makefile for:    iroffer-dinoex
# Date created:         10 Apr 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	iroffer
PORTVERSION=	3.14
CATEGORIES=	irc
MASTER_SITES=	http://iroffer.dinoex.net/
PKGNAMESUFFIX=	-dinoex${PKGNAMESUFFIX2}
DISTNAME=	iroffer-dinoex-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.ORG
COMMENT=	An IRC "bot" that makes sharing files via DCC extremely easy

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
MAN1=		iroffer.1

CONFLICTS=	iroffer-1* iroffer-lamm-1.*

OPTIONS=	CURL	"build ftp/http support"	on \
		RUBY	"build RUBY script support"	on \
		UPNP	"build UPNP support"		on \
		GEOIP	"build GEOIP support"		on \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	-curl
.endif
.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=	-geoip
.endif
.if defined(WITH_UPNP)
LIB_DEPENDS+=	miniupnpc.3:${PORTSDIR}/net/miniupnpc
CONFIGURE_ARGS+=	-upnp
.endif
.if defined(WITH_RUBY)
USE_RUBY=	yes
CONFIGURE_ARGS+=	-ruby
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.endif

do-patch:
	${REINPLACE_CMD} -e 's|int a;|int a=1;|' \
		-e 's|/usr/local/|${LOCLABASE}/|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-iroffer.txt ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.modDinoex ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/LIESMICH.modDinoex ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/THANKS ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/help-admin-en.txt ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/help-admin-de.txt ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/help-admin-it.txt ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/htdocs
	${INSTALL_DATA} ${WRKSRC}/iroffer.cron ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample.config ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/beispiel.config ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/header.html ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/footer.html ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/ruby-sample.rb ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/htdocs/iroffer-state.css \
		${WRKSRC}/htdocs/robots.txt \
		${EXAMPLESDIR}/htdocs/
.endif
	${INSTALL_MAN} ${WRKSRC}/iroffer.1 ${PREFIX}/man/man1/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
