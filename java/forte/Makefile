# New ports collection makefile for:    Forte for Java, Cummunity Edition
# Date created:				6 August 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	forte
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/forte/ffj/buy.html
DISTNAME=	ffj30_ce_ml
EXTRACT_SUFX=	.class
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Sun's powerful and extensible IDE for Java

USE_JAVA=	1.3+
JAVAVM=		${JAVA_HOME}/bin/java

RESTRICTED=	"Restrictive license"
USE_XLIB=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the source distribution (${DISTFILES}) from http://www.sun.com/forte/ffj/buy.html (registration required), place it in ${DISTDIR} and then run make again
.endif

do-configure:
	@${SED} "s|%%JDK13DIR%%|${JAVA_HOME}|g" \
		${FILESDIR}/forte.sh > ${WRKDIR}/forte.sh

pre-install:
.if exists(${PREFIX}/share/java/forte4j)
	@${ECHO_MSG}
	@${ECHO_MSG} "It seems that you already have \`${PREFIX}/share/java/forte4j' directory,"
	@${ECHO_MSG} "please remove it before proceeding with installation, otherwise installation"
	@${ECHO_MSG} "will hang."
	@${ECHO_MSG}
	@${FALSE}
.endif
	@if [ x"$${DISPLAY}" = x"" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "Due to limitations in installer you have to install this port from within"; \
		${ECHO_MSG} "X11 environment. However, the installation itself is fully automatic and"; \
		${ECHO_MSG} "doesn't require any user's interaction."; \
		${ECHO_MSG}; \
		${FALSE}; \
	fi

do-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/instscript | ${SETENV} \
		CLASSPATH=${DISTDIR} ${JAVAVM} ${DISTNAME} -nodisplay > /dev/null || ${TRUE}
	@${INSTALL_SCRIPT} ${WRKDIR}/forte.sh ${PREFIX}/share/java/forte4j/bin
	@${LN} -sf ${PREFIX}/share/java/forte4j/bin/forte.sh ${PREFIX}/bin/forte

.include <bsd.port.post.mk>
