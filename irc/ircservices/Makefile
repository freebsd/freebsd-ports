# New ports collection makefile for:	ircservices
# Date created:         Sun Oct 27 11:49:48 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	ircservices
PORTVERSION=	5.0.61
CATEGORIES=	irc
MASTER_SITES=	http://www.ircservices.za.net/download/ \
	ftp://ftp.esper.net/ircservices/ \
	ftp://ftp.ircd.com.br/ircservices/ \
	http://banana.irc.gr/ircservices/ \
	http://ircservices.swissirc.ch/ \
	ftp://ftp.freenet.de/pub/ftp.ircservices.za.net/pub/ircservices/

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	A system of IRC services for IRC networks

USE_PERL5_BUILD=yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	ircservices
USE_GCC=	3.2+

DIST_SUBDIR=	${PORTNAME}
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	-prefix ${PREFIX} -cflags "${CFLAGS}" -cc "${CC}"

IRCSERVICES_LANG?=	EN_US

.include <bsd.port.pre.mk>

.if ${ARCH}=="sparc64"
CONFIGURE_ARGS+=	-ignore-cache
CFLAGS:=	${CFLAGS:N-O*:N-pipe}
.endif

pre-patch:
	@${ECHO_MSG} "You can set IRCSERVICES_LANG to the following language"
	@${ECHO_MSG} "codes to select language the services will use when"
	@${ECHO_MSG} "communicating with users:"
	@${ECHO_MSG} "(Be aware of the capitalization!)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DE EN_US ES FR HU IT JA_EUC JA_SJIS NL PT RU TR"

post-patch:
	@${REINPLACE_CMD} -e 's|LANG_EN_US|LANG_${IRCSERVICES_LANG}|' \
		${WRKSRC}/defs.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/KnownBugs ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
