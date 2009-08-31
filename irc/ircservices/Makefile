# New ports collection makefile for:	ircservices
# Date created:         Sun Oct 27 11:49:48 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	ircservices
PORTVERSION=	5.1.18
CATEGORIES=	irc
MASTER_SITES=	http://www.ircservices.za.net/download/ \
		http://banana.irc.gr/ircservices/ \
		ftp://ftp.freenet.de/pub/ftp.ircservices.za.net/pub/ircservices/

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	A system of IRC services for IRC networks

USE_PERL5_BUILD=yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	ircservices

DIST_SUBDIR=	${PORTNAME}
CONFIGURE_ARGS=	-bindest ${PREFIX}/sbin -datdest ${PREFIX}/etc/ircservices -cflags "${CFLAGS}" -cc "${CC}"

IRCSERVICES_LANG?=	EN_US

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700042
CFLAGS+=	-fno-stack-protector
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

pre-patch:
	@${ECHO_MSG} "You can set IRCSERVICES_LANG to the following language"
	@${ECHO_MSG} "codes to select language the services will use when"
	@${ECHO_MSG} "communicating with users:"
	@${ECHO_MSG} "(Be aware of the capitalization!)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DE EN_US ES FR HU IT JA_EUC JA_SJIS NL PT TR"

post-patch:
	@${REINPLACE_CMD} -e 's|LANG_EN_US|LANG_${IRCSERVICES_LANG}|' \
		${WRKSRC}/defs.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
	@${ECHO_MSG} ""
	@${ECHO_MSG} "**********          IMPORTANT           **********"
	@${ECHO_MSG} "The configuration directory has changed to ${PREFIX}/etc/ircservices"
	@${ECHO_MSG} "Please copy your old config files there if updating"
	@${ECHO_MSG} "**********          IMPORTANT           *********"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.post.mk>
