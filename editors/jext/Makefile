# New ports collection makefile for:    jext
# Date created:				17 Febrary 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jext
PORTVERSION=	2.8.1.2
CATEGORIES=	editors java
MASTER_SITES=	http://www.jext.org/ \
		ftp://jext.sourceforge.net/pub/jext/archives/ \
		http://members.nbci.com/romainguy/ \
		http://members.xoom.com/romainguy/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} swingall.jar

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre

EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}
USE_XLIB=	yes
NO_BUILD=	yes

JAVAVM?=	${LOCALBASE}/bin/javavm

INSTSBDR=	${PREFIX}/share/java/jext

pre-patch:
	@${PERL} -pi -e 's.\x0D..' ${WRKSRC}/bin/jext.sh

do-configure:
	@${PERL} -pi -e 's|%%JAVAVM%%|${JAVAVM}|g			; \
			 s|%%JEXT_HOME%%|${INSTSBDR}|g			; \
			 s|%%JFC%%|${INSTSBDR}/lib/swingall.jar|g'	  \
			 ${WRKSRC}/bin/jext.sh

do-install:
	@${MKDIR} ${INSTSBDR}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/jext.sh ${PREFIX}/bin/jext
	@(cd ${WRKSRC} && ${TAR} -c -f - LICENSE README bin lib) \
		| (cd ${INSTSBDR} && ${TAR} --unlink -x -f -)
	@${INSTALL_DATA} ${DISTDIR}/swingall.jar ${INSTSBDR}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/java/jext
	@(cd ${WRKSRC}/docs && ${TAR} -c -f - * ) \
		| (cd ${PREFIX}/share/doc/java/jext && ${TAR} --unlink -x -f -)
.endif

.include <bsd.port.mk>
