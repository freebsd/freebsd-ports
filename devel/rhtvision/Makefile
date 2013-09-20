# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	rhtvision
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/tvision/UNIX/${PORTVERSION}%20CVS20070425%20Source%20and%20Debian%204.0/
DISTNAME=	rhtvision-${PORTVERSION}-3.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete C++ Text User Interface (TUI) library

WRKSRC=		${WRKDIR}/tvision
USES=		perl5
USE_GMAKE=	yes
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xrender xmu sm xt ice
PLIST_SUB+=	X11_ONLY=""
CFLAGS+=	-I${LOCALBASE}/include
.else
PLIST_SUB+=	X11_ONLY="@comment "

pre-configure:
	${ECHO} "HAVE_X11 => no" > ${WRKSRC}/configure.cache
.endif

post-patch:
.for f in config.pl confignt.pl conflib.pl linux/compress Makefile.in
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL5},g' \
		-e 's,/usr/local,${LOCALBASE},g' \
		-e 's,/usr/X11R6,${LOCALBASE},g' \
		-e 's,\(soname.*\)Version,\1VersionMajor,g' \
		-e 's/\tmake/\t\\$$(MAKE)/g' \
		-e 's/	make/	$$(MAKE)/g' \
		${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
