# Created by: rmallory@csusb.edu
# $FreeBSD$

PORTNAME=	rplay
PORTVERSION=	3.3.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://rplay.doit.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network audio player

LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

USE_LDCONFIG=	yes
NO_STAGE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		rplay.1 rptp.1
MAN5=		rplay.conf.5 rplay.helpers.5 rplay.hosts.5 rplay.servers.5
MAN8=		rplayd.8

INFO=		RPLAY RPTP librplay rplayd

.include <bsd.port.pre.mk>

USE_RC_SUBR=	rplayd

.if ${ARCH} == "amd64"
# pr ports/166658 mentions a problem with amd64. if it happens on i386, you can delete this conditional
# and rename to patch-ao
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ao
.endif

post-extract:
	@${CP} ${WRKSRC}/doc/rplay.texi ${WRKSRC}/doc/rplayd.texi

post-install:
	@${ECHO_MSG} "===>	startup file as ${PREFIX}/etc/rc.d/rplayd"
	@${MKDIR} ${PREFIX}/etc/
	for na in rplay.conf rplay.helpers rplay.servers rplay.hosts; do \
		${CP} ${WRKSRC}/etc/$$na ${PREFIX}/etc/$$na.sample; \
		if [ ! -f ${PREFIX}/etc/$$na ]; then \
			${CP} ${WRKSRC}/etc/$$na ${PREFIX}/etc/$$na; \
		fi; \
	done
.if !exists(${PREFIX}/etc/rplay.hosts)
	@${ECHO_CMD} localhost > ${PREFIX}/etc/rplay.hosts
.endif
	@${ECHO_CMD} localhost > ${PREFIX}/etc/rplay.hosts.sample

.include <bsd.port.post.mk>
