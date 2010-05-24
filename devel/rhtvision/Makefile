# New ports collection makefile for:	rhtvision
# Date created:		18 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	rhtvision
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	SF/tvision/UNIX/${PORTVERSION}%20CVS20070425%20Source%20and%20Debian%204.0/
DISTNAME=	rhtvision-${PORTVERSION}-3.src

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Complete C++ Text User Interface (TUI) library

WRKSRC=		${WRKDIR}/tvision
USE_PERL5=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

.if !defined(WITHOUT_X11)
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

.include <bsd.port.post.mk>
