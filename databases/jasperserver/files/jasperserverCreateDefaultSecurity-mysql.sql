
INSERT INTO `JITenant` (`id`, `tenantId`, `parentId`, `tenantName`, `tenantDesc`, `tenantNote`, `tenantUri`, `tenantFolderUri`) 
VALUES (1,'organizations',NULL,'root','organizations',' ','/','/');

INSERT INTO `JIRole` (`rolename`, `tenantId`,`externallyDefined`) VALUES 
 ('ROLE_USER',1,0),
 ('ROLE_ADMINISTRATOR',1,0),
 ('ROLE_ANONYMOUS',1,0),
 ('ROLE_PORTLET',1,0);

INSERT INTO `JIUser` (`username`,`tenantId`,`fullname`,`emailAddress`,`password`,`externallyDefined`,`enabled`) VALUES
('anonymousUser',1,'Anonymous User',NULL,'CF35D2E88192D6EB',0,1);
 
INSERT INTO `JIUserRole` (`userId`,`roleId`)
select u.id, r.id from JIUser u, JIRole r where u.username = 'anonymousUser' and r.roleName = 'ROLE_ANONYMOUS';

-- add jasperadmin user

INSERT INTO `JIUser` (`username`,`tenantId`,`fullname`,`emailAddress`,`password`,`externallyDefined`,`enabled`) VALUES
('jasperadmin',1,'Jasper Administrator',NULL,'349AFAADD5C5A2BD477309618DCD58B9',0,1);

INSERT INTO `JIUserRole` (`userId`,`roleId`)
select u.id, r.id from JIUser u, JIRole r where u.username = 'jasperadmin' and r.roleName = 'ROLE_ADMINISTRATOR';

INSERT INTO JIUserRole (userId,roleId)
select u.id, r.id from JIUser u, JIRole r where u.username = 'jasperadmin' and r.roleName = 'ROLE_USER';

INSERT INTO `JIResourceFolder` (`id`,`version`,`uri`,`hidden`,`name`,`label`,`description`,`parent_folder`,`creation_date`) VALUES 
(1,0,'/',0,'/','root','Root of the folder hierarchy',NULL,NOW());

INSERT INTO `JIObjectPermission` (`uri`,`recipientobjectclass`,`permissionMask`,`recipientobjectid`)
select 'repo:/','com.jaspersoft.jasperserver.api.metadata.user.domain.impl.hibernate.RepoRole', 1, r.id
from `JIRole` r where rolename = 'ROLE_ADMINISTRATOR';

INSERT INTO `JIObjectPermission` (`uri`,`recipientobjectclass`,`permissionMask`,`recipientobjectid`)
select 'repo:/','com.jaspersoft.jasperserver.api.metadata.user.domain.impl.hibernate.RepoRole', 2, r.id
from `JIRole` r where rolename = 'ROLE_USER';

