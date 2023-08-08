PORTNAME=	ndesk-options
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.ndesk.org/archive/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Callback-based program option parser for C\#
WWW=		http://www.ndesk.org/Options

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		gmake mono pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.in configure

post-extract:
	@${MV} ${WRKSRC}/lib ${WRKSRC}/libdata

.include <bsd.port.mk>
