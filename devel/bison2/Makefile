# ex:ts=8
# Ports collection makefile for:  bison
# Date created:			  27 Mar 1999
# Whom:				  Jerry Hicks
#
# $FreeBSD$
#

PORTNAME=		bison
PORTVERSION=		1.33
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	bison

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		giconv.2:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-included-gettext
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			MAKEINFO="makeinfo --no-split"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=			bison.1

post-extract:
	@${RM} -f ${WRKSRC}/doc/bison.info*
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e \
		's|-liconv|-lgiconv|g ; s|iconv\.h|giconv\.h|g'

post-install:
	install-info ${PREFIX}/info/bison.info ${PREFIX}/info/dir

.include <bsd.port.mk>
