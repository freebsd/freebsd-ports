# New ports collection makefile for:   pircbot
# Date created:                2 June 2002
# Whom:                        Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	pircbot
PORTVERSION=	0.9.10
CATEGORIES=	irc java
MASTER_SITES=	http://www.jibble.org/files/ \
		http://www.i-scream.org.uk/downloads/other/

MAINTAINER=	tim@bishnet.net

USE_ZIP=	yes
NO_BUILD=	yes

USE_JAVA=	1.1+

do-install:
	${INSTALL_DATA} ${WRKSRC}/pircbot.jar ${PREFIX}/share/java/classes
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pircbot
	(cd ${WRKSRC}/javadocs && ${TAR} -cf - . | ${TAR} -xf - -C ${PREFIX}/share/doc/pircbot)
.endif

post-install:
	@echo "    ---------------------------------------------------------------"
	@echo "    To use pircbot add ${PREFIX}/share/java/classes/pircbot.jar to"
	@echo "    your classpath. A short tutorial can be found here:"
	@echo "        http://www.jibble.org/pircbot.php"
.if !defined(NOPORTDOCS)
	@echo "    pircbot javadoc documentation has also been installed in:"
	@echo "        ${PREFIX}/share/doc/pircbot"
.endif
	@echo "    ---------------------------------------------------------------"

.include <bsd.port.mk>
