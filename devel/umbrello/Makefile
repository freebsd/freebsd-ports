# New ports collection makefile for:	UML
# Date created:				21 September 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uml
PORTVERSION=	1.0.3
DISTNAME=	uml-1.0.3-1
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
QTCFGLIBS+=	-pthread
CONFIGURE_ENV+=	LIBQT="-lqt-mt"
USE_GMAKE=	yes

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.dist

.include <bsd.port.mk>
