# New ports collection makefile for:	flux
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	flux
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.copyleft.no/projects/fluxlib/ \
		ftp://ftp.styx.net/projects/flux/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
USE_AUOTMAKE_VER=14
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/flux
	${TAR} -C ${WRKSRC}/doc --exclude ChangeLog -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/flux --unlink -xf -
	@find ${PREFIX}/share/doc/flux | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@find ${PREFIX}/share/doc/flux -type f | xargs ${CHMOD} ${SHAREMODE}
.for DOC in AUTHORS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/flux
.endfor
.endif

.include <bsd.port.mk>
