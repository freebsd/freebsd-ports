# New ports collection makefile for:	ircservices
# Date created:         Sun Oct 27 11:49:48 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	ircservices
PORTVERSION=	5.0.6
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.ircservices.za.net/pub/ircservices/ \
		ftp://ftp.esper.net/ircservices/

MAINTAINER=	sysadmin@alexdupre.com

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	-prefix ${PREFIX} -cflags "${CFLAGS}" -cc "${CC}"

post-install:
	@${ECHO_CMD} "Installing ${PREFIX}/etc/rc.d/ircservices.sh.sample startup file."
	@${INSTALL_SCRIPT} ${FILESDIR}/ircservices.sh \
		${PREFIX}/etc/rc.d/ircservices.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
