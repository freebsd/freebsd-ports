# ex:ts=8
# New ports collection makefile for:	make++
# Date created:			Fab 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	make++
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/+/p/g}
DISTNAME=	${PORTNAME:S/+/p/g}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5=	yes
DATADIR=	${PREFIX}/share/makepp

do-build:
	@${PERL} -pi -e "s|\@htmldir\@|${PREFIX}/share/makepp/html|g ; \
		s|\@datadir\@|${PREFIX}/share/makepp|g" ${WRKSRC}/makepp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makepp ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/Signature
	${INSTALL_SCRIPT} ${WRKSRC}/recursive_makepp ${DATADIR}
	@(cd ${WRKSRC} ; \
	  find . -name "*.pm" -maxdepth 1 -exec ${INSTALL_SCRIPT} {} ${DATADIR} \;)
	@(cd ${WRKSRC}/Signature ; \
	  find . -name "*.pm" -exec ${INSTALL_SCRIPT} {} ${DATADIR}/Signature \;)
	@(cd ${WRKSRC} ; \
	  find . -name "*.mk" -exec ${INSTALL_SCRIPT} {} ${DATADIR} \;)
	@${MKDIR} ${DATADIR}/html
	${CP} ${WRKSRC}/doc/* ${DATADIR}/html

.include <bsd.port.mk>
