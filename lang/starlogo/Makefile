# New ports collection makefile for:    StarLogo
# Date created:		14th November 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	starlogo
PORTVERSION=	1.2
CATEGORIES=	lang java
MASTER_SITES=	http://el.www.media.mit.edu/groups/el/Projects/starlogo/download/

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre

NO_BUILD=	yes

do-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/starlogo-unix

do-install:
	@${MKDIR} ${PREFIX}/share/java/starlogo
	@${INSTALL_SCRIPT} ${WRKSRC}/starlogo-unix ${PREFIX}/bin/starlogo
	@(cd ${WRKSRC} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/java/starlogo && && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>
