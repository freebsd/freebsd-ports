# ex:ts=8
# New ports collection makefile for:	autodia
# Date created:			Oct 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	autodia
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://droogs.org/autodia/download/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

USE_BZIP2=	yes
USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,%%PERL_VER%%,${PERL_VER},g" ${WRKSRC}/SRC/autodia.pl

do-install:
	@${MKDIR} ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/autodia
	${INSTALL_SCRIPT} ${WRKSRC}/SRC/autodia.pl ${PREFIX}/bin/autodia
	${CP} ${WRKSRC}/SRC/*.pm ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/autodia
	${CP} ${WRKSRC}/TEMPLATES/* ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/autodia

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/DOC/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
