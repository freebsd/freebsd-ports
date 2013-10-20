# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	baz
PORTVERSION=	1.4.2
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	http://bazaar-vcs.org/releases/src/obsolete/
DISTNAME=	bazaar_${PORTVERSION}

MAINTAINER=	ulf.lilleengen@gmail.com
COMMENT=	An implementation of the GNU Arch RCS protocol in C by Canonical

BUILD_DEPENDS=	gpatch:${PORTSDIR}/devel/patch \
		gdiff:${PORTSDIR}/textproc/diffutils \
		gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	neon.27:${PORTSDIR}/www/neon29 \
		libgpgme.so:${PORTSDIR}/security/gpgme

CONFLICTS=	gd-2.*

USES=		gettext gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		baz.1

MAJORVERSION=	1.4
BASEWRKDIR=	${WRKDIR}/thelove@canonical.com---dists--bazaar--${MAJORVERSION}
WRKSRC=		${BASEWRKDIR}/src/=build
PATCH_WRKSRC=	${BASEWRKDIR}
LDFLAGS+=	-L ${LOCALBASE}/lib
CFLAGS+=	-I ${LOCALBASE}/include ${LDFLAGS}

NO_STAGE=	yes
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
