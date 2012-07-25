# New ports collection makefile for:	rudiments
# Date created:		2 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudiments
PORTVERSION=	0.36.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility C++ class library for daemons, clients, servers, and more

LICENSE=	LGPL20

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config

USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	PTHREADINCLUDES="${PTHREAD_CFLAGS}" \
		PTHREADLIB="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-ssl-includes=-I${OPENSSLINC} \
		--with-ssl-libs=-L${OPENSSLLIB} \
		--disable-pcre
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		rudiments-config.1

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|$$(libdir)/|$$(prefix)/libdata/| ; \
		 /^install:/s| install-doc | |' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^#!/usr/bin/perl|#!${PERL}|' ${WRKSRC}/doc/programming/insert.pl
	@${REINPLACE_CMD} -e \
		's| -release $$(RUDIMENTS_VERSION)||' ${WRKSRC}/src/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(${TAR} -C ${WRKSRC}/doc --exclude CVS --exclude "Makefile" \
		--exclude "*.bak" --exclude "*.in" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -)
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
