# New ports collection makefile for:	httperf
# Date created:		28 Jul 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	httperf
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=		httperf.1

post-install:
	${CHMOD} 750 ${PREFIX}/bin/httperf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog NEWS README TODO
	@${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
