# ex:ts=8
# New ports collection makefile for:   dotconf
# Date created:                Jan 28, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotconf
PORTVERSION=	1.0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.azzit.de/dotconf/download/v1.0/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

pre-patch:
	@${PERL} -pi -e 's|-Wall -g||' ${WRKSRC}/configure
	@${PERL} -pi -e 's|-release $(LT_RELEASE)||' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples  -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
