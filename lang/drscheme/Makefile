# New ports collection makefile for:	DrScheme
# Date created:		21 Jun 2001
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drscheme
PORTVERSION=	300
CATEGORIES=	lang scheme
MASTER_SITES=	http://download.plt-scheme.org/bundles/${PORTVERSION}/plt/ \
		http://www.cs.utah.edu/plt/download/${PORTVERSION}/plt/ \
		ftp://ftp.pasteur.fr/pub/computing/Scheme/plt-scheme/${PORTVERSION}/plt/ \
		ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/${PORTVERSION}/plt/ \
		ftp://infogroep.be/pub/plt/bundles/${PORTVERSION}/plt/ \
		ftp://morpheus.wish.com.mx/pub/plt/${PORTVERSION}/plt/ \
		http://download.plt-scheme.org/patches/${PORTVERSION}/:PLT
DISTFILES=	plt-${PORTVERSION}-src-unix.tgz ${PLTPATCHES}
DIST_SUBDIR=	drscheme/${PORTVERSION}
EXTRACT_ONLY=	plt-${PORTVERSION}-src-unix.tgz

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	An interactive, integrated, graphical Scheme programming environment

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PLTHOME} --enable-shared	\
		--x-includes=${X11BASE}/include 	\
		--x-libraries=${X11BASE}/lib

OPTIONS=	CAIRO "use Cairo graphics" off

.include <bsd.port.pre.mk>

.if defined(WITH_CAIRO)
CONFIGURE_ARGS+= --enable-cairo
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
.else
CONFIGURE_ARGS+= --disable-cairo
.endif

WRKSRC=		${WRKDIR}/plt/src
USE_XLIB=	yes
USE_GMAKE=	yes

PLTHOME=	${PREFIX}/drscheme
PLTPATCHES=	# none yet for this version
DRS_B=		drscheme gmzc help-desk mred mzc mzscheme planet tex2page
MAN1=		drscheme.1 help-desk.1 mred.1 mzscheme.1 tex2page.1

ONLY_FOR_ARCHS=	i386

post-install:
.for f in ${PLTPATCHES}
	cd ${PLTHOME} && bin/setup-plt ${_DISTDIR}/${f:S/:PLT//}
.endfor
.for f in ${DRS_B}
	${LN} -s ${PLTHOME}/bin/$f ${PREFIX}/bin/$f
.endfor
.for f in ${MAN1}
	${INSTALL_MAN} ${PLTHOME}/man/man1/$f ${PREFIX}/man/man1/
.endfor

.include <bsd.port.post.mk>
