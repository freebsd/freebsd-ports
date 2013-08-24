# Created by: Ruslan Shevchenko <rssh@satori.ipri.kiev.ua>
# $FreeBSD$

PORTNAME=	sr
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	lang parallel
MASTER_SITES=	ftp://ftp.cs.arizona.edu/sr/
DISTNAME=	sr${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel language from the University of Arizona

USES=		gmake	# required to support parallel (-jX) builds
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	prefix
CONFIGURE_ENV=	PREFIX="${PREFIX}"
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" MAKE="${MAKE_CMD}"
REINPLACE_ARGS=	-i ''

NO_WRKSUBDIR=	yes

MAN1=		sr.1 srl.1 srm.1 srprof.1 srtex.1 srlatex.1 srgrind.1 \
		ccr2sr.1 m2sr.1 csp2sr.1
MAN3=		sranimator.3 srgetopt.3 srwin.3
MAN5=		srmap.5 srtrace.5

OPTIONS_DEFINE=	X11 DOCS EXAMPLES
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} != "i386"
BROKEN=		does not compile on ${ARCH}
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
.endif

# Make parallel builds (-jX) actually work: sanitize make(1) syntax
post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-E 's/cd (.+);[[:blank:]]*(\$$\(R?MAKE\))/\2 -C \1/ ; \
		s/RMAKE/MAKE/'

pre-su-install:
	@${MKDIR} ${PREFIX}/lib/sr

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/notes ${DOCSDIR}/ps
	${INSTALL_DATA} ${WRKSRC}/notes/* ${DOCSDIR}/notes
	${INSTALL_DATA} ${WRKSRC}/ps/* ${DOCSDIR}/ps
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -a ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
