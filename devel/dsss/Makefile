# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsss
PORTVERSION=	0.78
CATEGORIES=	devel
MASTER_SITES=	http://svn.dsource.org/projects/dsss/downloads/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	D Shared Software System

DEPRECATED=	Depends on expired lang/gdc
EXPIRATION_DATE=2013-09-01

BUILD_DEPENDS=	gdc:${PORTSDIR}/lang/gdc

USE_BZIP2=	yes
MAKEFILE=	Makefile.gdc.posix

MAKE_ENV=	NATIVECXX="${CXX}"
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

MAN1=		dsss.1 rebuild.1

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900027
BROKEN=		does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/dsss.conf
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|install docs.*share/doc/dsss ;||' \
		${WRKSRC}/dsss.conf
.endif
.for var in CXX NATIVECXX CXXFLAGS PREFIX
	@${REINPLACE_CMD} -e '/^${var}=/ d' ${WRKSRC}/${MAKEFILE} \
		${WRKSRC}/rebuild/Makefile
.endfor

.include <bsd.port.mk>
