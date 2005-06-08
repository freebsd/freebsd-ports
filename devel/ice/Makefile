# New ports collection makefile for:	ice
# Date created:		2004-02-02
# Whom:			Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	Ice
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.zeroc.com/download/Ice/2.1/

MAINTAINER=	shoesoft@gmx.net
COMMENT=	A modern alternative to object middleware such as CORBA/COM/DCOM/COM+

LIB_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42 \
		expat.5:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS}
.if defined(DEBUG)
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500028
BROKEN=	"does not compile on systems prior to 5.x"
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

post-patch:
	${SED} 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g; \
		s|%%PREFIX%%|${PREFIX}|g; \
		s|%%DATADIR%%|${DATADIR}|g; \
		s|%%DOCSDIR%%|${DOCSDIR}|g;' \
		${FILESDIR}/Make.rules.FreeBSD > ${WRKSRC}/config/Make.rules.FreeBSD
	${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g' ${WRKSRC}/config/Make.rules
	${FIND} ${WRKSRC} -name Makefile -exec ${REINPLACE_CMD} 's|-lIceSSL|-lIceSSL -lIceXML|' {} \;

.include <bsd.port.post.mk>
