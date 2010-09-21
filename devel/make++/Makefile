# ex:ts=8
# New ports collection makefile for:	make++
# Date created:			Fab 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	make++
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	SF/makepp/makepp/${PORTVERSION}
DISTNAME=	${PORTNAME:S/+/p/g}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drop-in replacement for GNU make

USE_PERL5=	yes
DATADIR=	${PREFIX}/share/makepp

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

do-build:
	@${PERL} -pi -e "s|\@htmldir\@|${PREFIX}/share/makepp/html|g ; \
		s|\@datadir\@|${PREFIX}/share/makepp|g" ${WRKSRC}/makepp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makepp ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/Signature
	${INSTALL_SCRIPT} ${WRKSRC}/recursive_makepp ${DATADIR}
	@(cd ${WRKSRC} ; \
	  ${FIND} . -name "*.pm" -maxdepth 1 -exec ${INSTALL_SCRIPT} {} ${DATADIR} \;)
	@(cd ${WRKSRC}/Signature ; \
	  ${FIND} . -name "*.pm" -exec ${INSTALL_SCRIPT} {} ${DATADIR}/Signature \;)
	@(cd ${WRKSRC} ; \
	  ${FIND} . -name "*.mk" -exec ${INSTALL_SCRIPT} {} ${DATADIR} \;)

.include <bsd.port.post.mk>
