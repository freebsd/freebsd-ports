# New ports collection makefile for:	sr
# Date created:			2 Jun 1997
# Whom:				Ruslan Shevchenko <rssh@satori.ipri.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	sr
PORTVERSION=	2.3.1
CATEGORIES=	lang parallel
MASTER_SITES=	ftp://ftp.uu.net/.vol/1/languages/sr/ \
		http://www.it.uc3m.es/~ptb/clases/sr/inst/src/ \
		ftp://ftp.cs.arizona.edu/sr/
DISTNAME=	sr231
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parallel language "Synchronization Resources"

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	prefix
CONFIGURE_ENV=	PREFIX="${PREFIX}"
NO_WRKSUBDIR=	yes
MAN1 =		sr.1 srl.1 srm.1 srprof.1 srtex.1 srlatex.1 srgrind.1 \
		ccr2sr.1 m2sr.1 csp2sr.1
MAN3 =		sranimator.3 srgetopt.3 srwin.3
MAN5 =		srmap.5 srtrace.5

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment "
.else
PLIST_SUB+=	X11=""
USE_XLIB=	yes
.endif

.include	<bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		"Does not compile on !i386 and !alpha"
.endif

pre-install:
	@${MKDIR} ${PREFIX}/lib/sr

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/notes
	${MKDIR} ${DOCSDIR}/ps
	${INSTALL_DATA} ${WRKSRC}/notes/* ${DOCSDIR}/notes
	${INSTALL_DATA} ${WRKSRC}/ps/* ${DOCSDIR}/ps
	${MKDIR} ${EXAMPLESDIR}
	${CP} -pR ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include	<bsd.port.post.mk>
