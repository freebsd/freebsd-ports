# New ports collection makefile for:	ezbounce
# Date created:	 	19 February 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ezbounce
PORTVERSION=	1.04.b
CATEGORIES=	irc
MASTER_SITES=	http://druglord.freelsd.org/ezbounce/ \
		http://ezbounce.dc-team.com/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	joe@joeholden.co.uk
COMMENT=	A highly configurable IRC Proxy

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

MAN1=		ezbounce.1

.if !defined(WITH_MDIDENTD)
ALL_TARGET=	ezbounce_src
PLIST_SUB+=	MDIDENTD="@comment "
.else
PLIST_SUB+=	MDIDENTD=""
.endif

.if defined(WITH_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	--with-ssl
PLIST_SUB+=	SSL=""
.else
PLIST_SUB+=	SSL="@comment "
.endif

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_SSL=yes      Enable SSL support"
	@${ECHO_MSG} "	WITH_MDIDENTD=yes Install the mdidentd binary to"
	@${ECHO_MSG} "                        modify ident replies"
	@${ECHO_MSG} ""

post-patch:
	@${SED} -e "s:/path/to:${PREFIX}/sbin:" ${WRKSRC}/sample.conf > \
		${WRKSRC}/ezb.conf.default
	@${REINPLACE_CMD} -e 's|=-O2|="$$CXXFLAGS"|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezb.conf.default ${PREFIX}/etc
	${INSTALL_MAN}	${WRKSRC}/misc/ezbounce.1 ${PREFIX}/man/man1

.if defined(WITH_MDIDENTD)
	${INSTALL_PROGRAM} ${WRKSRC}/mdidentd/mdidentd ${PREFIX}/sbin
.endif

	@if [ ! -f ${PREFIX}/etc/ezb.conf ]; then \
		${INSTALL_DATA} \
		${WRKSRC}/ezb.conf.default ${PREFIX}/etc/ezb.conf; \
	fi

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/worklog ${DOCSDIR}

.if defined(WITH_MDIDENTD)
	${INSTALL_DATA} ${WRKSRC}/mdidentd/README \
		${DOCSDIR}/mdidentd.README
.endif
.if defined(WITH_SSL)
	${INSTALL_DATA} ${WRKSRC}/README.SSL ${DOCSDIR}
.endif

.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
