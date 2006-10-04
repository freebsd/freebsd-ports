# New ports collection makefile for:	ircservices
# Date created:         Sun Oct 27 11:49:48 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	ircservices
PORTVERSION=	5.0.${PATCHLEVEL}
CATEGORIES=	irc
MASTER_SITES=	http://www.ircservices.za.net/download/ \
	ftp://ftp.esper.net/ircservices/ \
	ftp://ftp.ircd.com.br/ircservices/ \
	http://banana.irc.gr/ircservices/ \
	http://ircservices.swissirc.ch/ \
	ftp://ftp.freenet.de/pub/ftp.ircservices.za.net/pub/ircservices/ 

DISTNAME=	${PORTNAME}-5.0.0

PATCH_SITES=	${MASTER_SITES}
PATCHLEVEL=	59
PATCHFILES!=	/usr/bin/jot -s " " -w ${DISTNAME:C/[0-9]*$//}%d.diff.gz  \
			${PATCHLEVEL} 1 ${PATCHLEVEL}
PATCH_DIST_STRIP=	-p1

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

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/KnownBugs ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
