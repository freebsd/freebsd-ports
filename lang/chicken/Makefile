# New ports collection makefile for:	CHICKEN
# Date created:				31 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	chicken
PORTVERSION=	1.33
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Scheme-to-C compiler

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
USE_GNOME=	lthack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		chicken-config.1 chicken-setup.1 chicken.1 csc.1 csi.1

post-patch:
	${REINPLACE_CMD} -e 's/\(install-data-am: \)install-data-local/\1/' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|"/usr/local/include" ||' ${WRKSRC}/csc.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
