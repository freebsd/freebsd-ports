# New ports collection makefile for:	VJE-Delta 3.0 + update
# Date created:		29 January 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	vje
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	file:${MOUNT_PT}/freebsd/ \
		file:${MOUNT_PT}/source/delta/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTFILES=	${MAINDIST} \
		vje-delta-3.0-${DISTOBJFORMAT}-update.tgz \
		delta.tgz \
		vje-delta-3.0-source-update.tgz
DIST_SUBDIR=	vje30

MAINTAINER=	knu@FreeBSD.org

#RUN_DEPENDS=	${LOCALBASE}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc

RESTRICTED=	"You must purchase a licensed copy from VACS Corporation."
NO_CDROM=	"You must purchase a licensed copy from VACS Corporation."
NO_PACKAGE=	"You must purchase a licensed copy from VACS Corporation."

# Specify this!
MOUNT_PT?=	/cdrom

ONLY_FOR_ARCHS=	i386

USE_XLIB=	yes

PLIST_SUB=	BINSTUFF="${BINSTUFF}"

WRKSRC=		${WRKDIR}/usr/local
PATCH_WRKSRC=	${WRKDIR}
BUILD_WRKSRC=	${WRKDIR}/delta/newFrontend
MAKEFILE=	Makefile.FreeBSD

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTOBJFORMAT=	AOUT
.else
DISTOBJFORMAT=	ELF
.endif

MAINDIST=	${PORTNAME}-delta-${PORTVERSION}-${DISTOBJFORMAT}.tgz

BINSTUFF=	vje	\
		vjed	\
		vadd	\
		vdel	\
		vdispd	\
		vmaked	\
		vpen	\
		vpu	\
		vjekill	\
		vpr	\
		vprc	\
		vjeacc

pre-fetch:
	@[ -d ${MOUNT_PT}/freebsd ] || ( \
	${ECHO} "*****************************************************************";	\
	${ECHO} "To install VJE-Delta 3.0, make sure your purchased CD-ROM is";		\
	${ECHO} "mounted on at ${MOUNT_PT} or an arbitrary mountpoint that can be";	\
	${ECHO} "specified by setting MOUNT_PT variable in a make command line.";	\
	${ECHO} "";									\
	${ECHO} "e.g.";									\
	${ECHO} "	mount /dev/cd0c /mnt/cdrom";					\
	${ECHO} "	make MOUNT_PT=/mnt/cdrom install";				\
	${ECHO} "*****************************************************************";	\
	${FALSE}									\
	)

post-extract:
	@${RM} ${_DISTDIR}/${MAINDIST} ${WRKDIR}/vje

post-patch:
	@cd ${WRKSRC}/vje30/bin && ${RM} swingall.jar
	@find ${WRKSRC} -name '*.orig' -delete
	@${CP} ${FILESDIR}/vje.sh ${WRKSRC}/etc/rc.d/
	@${PERL} -i -pe 's,/usr/X11R6,${X11BASE},g' ${BUILD_WRKSRC}/${MAKEFILE}
.if defined(NOPORTDOCS)
	@cd ${WRKSRC}/vje30 && ${RM} -rf doc README FAQ REQUEST
.endif

post-build:
	@${CP} ${BUILD_WRKSRC}/vje ${WRKSRC}/vje30/bin/

do-install:
	@cd ${WRKSRC} && tar cf - . | tar xf - -C ${PREFIX}
.for f in ${BINSTUFF}
	@${LN} -fs ${PREFIX}/vje30/bin/$f ${PREFIX}/bin/$f
.endfor
	@${CHMOD} a+x ${PREFIX}/etc/rc.d/vje.sh
	@${CHMOD} a+w ${PREFIX}/vje30/dic/vjed95m.dic
	@[ X${PREFIX} = X"/usr/local" ] || (${LN} -s ${PREFIX}/vje30 /usr/local/; ${LN} -s ${PREFIX}/etc/vje30 /usr/local/etc/)
	@${CP} ${WRKDIR}/vjed.bin /tmp/
	@${ECHO} '' | ${WRKDIR}/vjesetup
	@${RM} /tmp/vjed.bin
	@${CP} -Pp /etc/services /etc/services.bak
	@${GREP} -qw '^vjed' /etc/services || ${ECHO} "vjed		11493/tcp		# VJE-Delta Server" >> /etc/services

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
