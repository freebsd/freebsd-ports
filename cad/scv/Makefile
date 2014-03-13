# Created by: Peter Johnson
# $FreeBSD$

PORTNAME=	scv
PORTVERSION=	1.0p2
CATEGORIES=	cad devel
MASTER_SITES=	# you have to register and manually fetch
EXTRACT_SUFX=	-sysc2.2.12jun06.tgz

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	SystemC Verification library

BUILD_DEPENDS=	${LOCALBASE}/systemc/lib-freebsd/libsystemc.a:${PORTSDIR}/cad/systemc
RUN_DEPENDS=	${LOCALBASE}/systemc/lib-freebsd/libsystemc.a:${PORTSDIR}/cad/systemc

RESTRICTED=	You have to register at http://www.systemc.org/account/register.php first

USES=		gmake
HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/scv-1.0p2-sysc2.2
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=		--with-systemc=${LOCALBASE}/systemc ${CONFIGURE_TARGET}
CONFIGURE_WRKSRC=	${WRKSRC}/objdir
BUILD_WRKSRC=	${WRKSRC}/objdir
INSTALL_WRKSRC=	${WRKSRC}/objdir

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		is restricted. You have to register at http://www.systemc.org/account/register.php and download ${DISTFILES} from there first. Then put ${DISTFILES} into ${DISTDIR} and run make again
.endif

pre-configure:
	@${MKDIR} ${WRKSRC}/objdir

.include <bsd.port.post.mk>
