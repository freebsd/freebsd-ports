# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	fb303
PORTVERSION=	${THRIFT_PORTVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	thrift/${PORTVERSION}
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	Facebook Bassline

LICENSE=	AL2

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		thrift:${PORTSDIR}/devel/thrift

ACLOCAL_ARGS=	-I ./aclocal
AUTOMAKE_ARGS=	-a
CONFIGURE_ARGS=	PY_PREFIX="${PREFIX}"
USE_AUTOTOOLS=	aclocal automake autoconf
USE_GMAKE=	yes
USES=		perl5
USE_PERL5=	run
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/fb303

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

NO_STAGE=	yes
post-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/thrift --gen perl ${WRKSRC}/if/fb303.thrift)

post-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/Facebook/FB303
.for FILE in Constants.pm FacebookService.pm Types.pm
	${INSTALL_DATA} ${WRKSRC}/gen-perl/Facebook/FB303/${FILE} ${PREFIX}/${SITE_PERL_REL}/Facebook/FB303
.endfor

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
