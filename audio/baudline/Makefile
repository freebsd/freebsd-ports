# New ports collection makefile for:	baudline
# Date created:				19 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	baudline
PORTVERSION=	0.88
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/sigfriedblip/baudline/
DISTNAME=	baudline_${PORTVERSION:S/.p/pre/}_i686

MAINTAINER=	dyeske@yahoo.com

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

DOCDIR=		share/doc/${PORTNAME}
DOC_FILES=	mailcap.txt mime.types.txt README
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"author requests no distribution except from their site"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}
USE_X_PREFIX=	yes
NO_BUILD=	yes
LINPROCFS!=	/sbin/mount | /usr/bin/grep linprocfs | /usr/bin/awk '{print $1}'

.include <bsd.port.pre.mk>

pre-fetch:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} Check if linprocfs is running: YES
.else
	@${ECHO} -----------------------------------------------------------
	@${ECHO}
	@${ECHO} Baudline needs a running linprocfs, which is not
	@${ECHO} activated on your system. Please read the linprocfs\(5\)
	@${ECHO} manpage and add the following line to /etc/fstab:
	@${ECHO}
	@${ECHO} linproc /compat/linux/proc linprocfs rw 0 0
	@${ECHO}
	@${ECHO} -----------------------------------------------------------
	@${FALSE}
.endif

pre-install:
	${ECHO} bin/baudline > ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOC_FILES}
	${ECHO} ${DOCDIR}/`${BASENAME} ${i}` >> ${PLIST}
.endfor
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${CP} ${WRKSRC}/baudline ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.post.mk>
