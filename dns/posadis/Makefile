# New ports collection makefile for:	posadis
# Date Created:				27 Feb 2003
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	posadis
PORTVERSION=	0.50.9
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@kolobov.com
COMMENT=	"Domain Name Server (DNS) implementation"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}" --disable-gtk

MAN1=		posadis.1 posctl.1 posask.1
MAN5=		posadis.conf.5 posadis-domains.conf.5
DOCS=		AUTHORS ChangeLog NEWS README TODO

post-patch:
	${RM} -f ${WRKSRC}/doc/posadis.info*

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
