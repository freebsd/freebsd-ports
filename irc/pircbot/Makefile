# New ports collection makefile for:   pircbot
# Date created:                2 June 2002
# Whom:                        Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	pircbot
PORTVERSION=	1.4.2
CATEGORIES=	irc java
MASTER_SITES=	http://www.jibble.org/files/ \
		ftp://ftp.i-scream.org/pub/www.jibble.org/files/ \
		http://www.i-scream.org/pub/www.jibble.org/files/

MAINTAINER=	tim@bishnet.net
COMMENT=	PircBot Java IRC Bot Framework

USE_ZIP=	yes
NO_BUILD=	yes

USE_JAVA=	1.1+

do-install:
	${INSTALL_DATA} ${WRKSRC}/pircbot.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/javadocs && ${TAR} -cf - . | ${TAR} -xf - -C ${DOCSDIR})
.endif

post-install:
	@${ECHO_MSG} "    ---------------------------------------------------------------"
	@${ECHO_MSG} "    To use pircbot add ${JAVAJARDIR}/pircbot.jar to"
	@${ECHO_MSG} "    your classpath. A short tutorial can be found here:"
	@${ECHO_MSG} "        http://www.jibble.org/pircbot.php"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "    pircbot javadoc documentation has also been installed in:"
	@${ECHO_MSG} "        ${DOCSDIR}"
.endif
	@${ECHO_MSG} "    ---------------------------------------------------------------"

.include <bsd.port.mk>
