# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.3.0
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	jupengfei@gmail.com
COMMENT=	ODBC library suite for Unix

CONFLICTS=	firebird-client-* libiodbc-[0-9]* virtuoso-*

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static --enable-shared \
		--with-libiconv-prefix=${LOCALBASE}
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} 's,$$LIBS $$THREADLIB,$$LIBS,;s,$$CFLAGS -pthread,$$CFLAGS,' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,@MSQL_TRUE@lib_LTLIBRARIES,#&,' \
		${WRKSRC}/Drivers/MiniSQL/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . \
		| ${TAR} -C ${DOCSDIR} --unlink -xf -
.if !defined(INSTALL_AS_USER)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.endif
.endif

.include <bsd.port.mk>
