# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icoutils
PORTVERSION=	0.31.0
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	RESSCRIPTS
RESSCRIPTS_DESC=	PERL resource scripts

USE_BZIP2=	yes
USES=		shebangfix
SHEBANG_FILES=	extresso/*.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		icotool.1 wrestool.1
PLIST_FILES=	bin/icotool \
		bin/wrestool

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRESSCRIPTS}
RUN_DEPENDS+=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
USES+=		perl5
USE_PERL5=	run
MAN1+=		extresso.1 genresscript.1
PLIST_FILES+=	bin/extresso \
		bin/genresscript
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|extresso||' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MRESSCRIPTS}
	@(cd ${WRKSRC}/extresso && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.include <bsd.port.post.mk>
