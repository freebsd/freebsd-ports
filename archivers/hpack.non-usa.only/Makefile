# New ports collection makefile for:    hpack.with_encryption
# Version required:     0.79a0
# Date created:         7 Jan 1995
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       hpack79src
PKGNAME=        hpack-0.79a
CATEGORIES=	archivers
MASTER_SITES=   ftp://src.doc.ic.ac.uk/packages/hpack/

MAINTAINER=     ache@FreeBSD.org

RESTRICTED=	"Using this code inside USA will violate RSA patents"
NO_WRKSUBDIR=	yes
MAKEFILE=       makefile
ALL_TARGET=     freebsd
INSTALL_TARGET= freebsd.install
MAN1=		hpack.1

post-patch:
.for f in language/language.c cli.c
	@${PERL} -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
