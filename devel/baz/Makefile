# Ports collection makefile for:	bazaar
# Date created:		11 October 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bazaar
PORTVERSION=	1.4.2
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://bazaar-vcs.org/releases/src/obsolete/
DISTNAME=	bazaar_${PORTVERSION}

MAINTAINER=	ulf.lilleengen@gmail.com
COMMENT=	An implementation of the GNU Arch RCS protocol in C by Canonical

BUILD_DEPENDS=	gpatch:${PORTSDIR}/devel/patch \
		gdiff:${PORTSDIR}/textproc/diffutils \
		gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	neon.28:${PORTSDIR}/www/neon28 \
		gpgme.18:${PORTSDIR}/security/gpgme

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		baz.1

MAJORVERSION=	1.4
BASEWRKDIR=	${WRKDIR}/thelove@canonical.com---dists--bazaar--${MAJORVERSION}
WRKSRC=		${BASEWRKDIR}/src/=build
PATCH_WRKSRC=	${BASEWRKDIR}
LDFLAGS+=	-L ${LOCALBASE}/lib
CFLAGS+=	-I ${LOCALBASE}/include ${LDFLAGS}

.include <bsd.port.pre.mk>

pre-patch:
	${MKDIR} ${WRKSRC}

# I know the CFLAGS export is ugly, but it's the only way i've gotten bazaars
# own autotools to detect libraries the "correct" way.
do-configure:
	cd ${WRKSRC} && export CFLAGS="${CFLAGS}" \
			&& ../configure --prefix ${PREFIX} \
			--with-gnu-patch gpatch \
			--with-gnu-diff gdiff \
			--with-gnu-diff3 gdiff3 \
			--with-gnu-tar gtar

post-install:
	cd ${BASEWRKDIR}/src/baz-manpage && ${PERL} generate-manpage.pl ${MAN1}\
	&& \
	${INSTALL_MAN} ${BASEWRKDIR}/src/baz-manpage/${MAN1} \
	${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
