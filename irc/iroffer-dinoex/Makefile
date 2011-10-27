# New ports collection makefile for:    iroffer-dinoex
# Date created:         10 Apr 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	iroffer
PORTVERSION=	3.27
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://iroffer.dinoex.net/
PKGNAMESUFFIX=	-dinoex${PKGNAMESUFFIX2}
DISTNAME=	iroffer-dinoex-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An IRC "bot" that makes sharing files via DCC extremely easy

LICENSE=	GPLv2
CONFLICTS=	iroffer-1* iroffer-lamm-1.*

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
MAN1=		iroffer.1
CONFIGURE_ARGS=	CC="${CC}" LDFLAGS="${LDFLAGS}" LOCALBASE="${LOCALBASE}"
ALL_TARGET=	all-lang doc
USE_RC_SUBR=	iroffer-dinoex

IROFFER_DOCS=	README README.modDinoex LIESMICH.modDinoex \
		LICENSE THANKS TODO \
		help-admin-de.txt help-admin-en.txt \
		help-admin-fr.txt help-admin-it.txt \
		doc/iroffer.1.txt doc/iroffer.1.html doc/iroffer.1.ps \
		doc/INSTALL-linux-de.html doc/INSTALL-linux-de.txt \
		doc/INSTALL-linux-en.html doc/INSTALL-linux-en.txt \
		doc/INSTALL-linux-fr.html doc/INSTALL-linux-fr.txt \
		doc/INSTALL-linux-it.html doc/INSTALL-linux-it.txt \
		doc/INSTALL-vhost-de.html doc/INSTALL-vhost-de.txt \
		doc/INSTALL-vhost-en.html doc/INSTALL-vhost-en.txt \
		doc/INSTALL-vhost-fr.html doc/INSTALL-vhost-fr.txt
IROFFER_EXAMPLES= iroffer.cron \
		sample.config beispiel.config exemple.config \
		header.html footer.html ruby-sample.rb
IROFFER_HTDOCS=	iroffer-state.css robots.txt \
		info.txt.rb md5.txt.rb sfv.txt.rb

OPTIONS=	CURL	"build ftp/http support"	on \
		RUBY	"build RUBY script support"	on \
		UPNP	"build UPNP support"		on \
		GEOIP	"build GEOIP support"		on \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	-curl
.endif
.if !defined(WITHOUT_GEOIP)
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=	-geoip
.endif
.if !defined(WITHOUT_UPNP)
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
CONFIGURE_ARGS+=	-upnp
.endif
.if !defined(WITHOUT_RUBY)
USE_RUBY=	yes
CONFIGURE_ARGS+=	-ruby
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer-de ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer-it ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/iroffer-fr ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${IROFFER_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/htdocs
.for i in ${IROFFER_HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/${i} ${EXAMPLESDIR}/htdocs/
.endfor
.for i in ${IROFFER_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}/
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/iroffer.1 ${PREFIX}/man/man1/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
