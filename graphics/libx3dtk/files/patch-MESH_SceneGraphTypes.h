*** include/X3DTK/private/MESH_SceneGraphTypes.h.orig	Fri Aug 27 13:18:32 2004
--- include/X3DTK/private/MESH_SceneGraphTypes.h	Sat Oct 29 12:40:12 2005
***************
*** 112,118 ****
      typename Base::iterator it = Base::find(element->getIndex());
      if ((*it).second == element)
        return it;
!     return end();  
    }
    
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
--- 112,118 ----
      typename Base::iterator it = Base::find(element->getIndex());
      if ((*it).second == element)
        return it;
!     return Base::end();  
    }
    
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
***************
*** 121,127 ****
      typename Base::const_iterator it = Base::find(element->getIndex());
      if ((*it).second == element)
        return it;
!     return end();  
    }
  };
  
--- 121,127 ----
      typename Base::const_iterator it = Base::find(element->getIndex());
      if ((*it).second == element)
        return it;
!     return Base::end();  
    }
  };
  
***************
*** 163,169 ****
    /// operator[].
    SFTemplateEdge<MData, VData, EData, FData, RW> *const &operator[](const unsigned int &n) const
    {
!     typename Base::const_iterator it = begin();
      for (unsigned int i = 0; i < n; ++i)
        ++it;
      return *it;  
--- 163,169 ----
    /// operator[].
    SFTemplateEdge<MData, VData, EData, FData, RW> *const &operator[](const unsigned int &n) const
    {
!     typename Base::const_iterator it = Base::begin();
      for (unsigned int i = 0; i < n; ++i)
        ++it;
      return *it;  
***************
*** 220,226 ****
      typename Base::iterator it = Base::find(element->getIndex());
      if ((*it).second == element)  
        return it;
!     return end();
    }
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::map<unsigned int, SFTemplateFace<MData, VData, EData, FData, RW> *>::const_iterator find(SFTemplateFace<MData, VData, EData, FData, RW> *const &element) const
--- 220,226 ----
      typename Base::iterator it = Base::find(element->getIndex());
      if ((*it).second == element)  
        return it;
!     return Base::end();
    }
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::map<unsigned int, SFTemplateFace<MData, VData, EData, FData, RW> *>::const_iterator find(SFTemplateFace<MData, VData, EData, FData, RW> *const &element) const
***************
*** 228,234 ****
      typename Base::const_iterator it = Base::find(element->getIndex());
      if ((*it).second == element)  
        return it;
!     return end(); 
    }
  };
  
--- 228,234 ----
      typename Base::const_iterator it = Base::find(element->getIndex());
      if ((*it).second == element)  
        return it;
!     return Base::end(); 
    }
  };
  
***************
*** 262,271 ****
    /// Inserts element x at index x.first of the std::vector. Is provided to have common interface with std::map.
    std::pair<typename std::vector<SFTemplateVertex<MData, VData, EData, FData, false> *>::iterator, bool> insert(const std::pair<unsigned int, SFTemplateVertex<MData, VData, EData, FData, false> *> &x)
    {
!     if (x.first >= size())
        resize(x.first + 1, 0);
    
!     typename Base::iterator it = begin();
      it += x.first;
      *it = x.second;
      
--- 262,271 ----
    /// Inserts element x at index x.first of the std::vector. Is provided to have common interface with std::map.
    std::pair<typename std::vector<SFTemplateVertex<MData, VData, EData, FData, false> *>::iterator, bool> insert(const std::pair<unsigned int, SFTemplateVertex<MData, VData, EData, FData, false> *> &x)
    {
!     if (x.first >= Base::size())
        resize(x.first + 1, 0);
    
!     typename Base::iterator it = Base::begin();
      it += x.first;
      *it = x.second;
      
***************
*** 275,281 ****
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateVertex<MData, VData, EData, FData, false> *>::iterator find(SFTemplateVertex<MData, VData, EData, FData, false> *const &element) const
    {
!     return std::find(begin(), end(), element);
    }
  
  };
--- 275,281 ----
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateVertex<MData, VData, EData, FData, false> *>::iterator find(SFTemplateVertex<MData, VData, EData, FData, false> *const &element) const
    {
!     return std::find(Base::begin(), Base::end(), element);
    }
  
  };
***************
*** 307,319 ****
    std::pair<typename std::vector<SFTemplateEdge<MData, VData, EData, FData, false> *>::iterator, bool> insert(const typename std::vector<SFTemplateEdge<MData, VData, EData, FData, false> *>::value_type &x)
    {
      push_back(x);
!     return std::pair<typename Base::iterator, bool>(end(), true);
    }
  
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateEdge<MData, VData, EData, FData, false> *>::iterator find(SFTemplateEdge<MData, VData, EData, FData, false> *const &element) const
    {
!     return std::find(begin(), end(), element);
    }
  };
  
--- 307,319 ----
    std::pair<typename std::vector<SFTemplateEdge<MData, VData, EData, FData, false> *>::iterator, bool> insert(const typename std::vector<SFTemplateEdge<MData, VData, EData, FData, false> *>::value_type &x)
    {
      push_back(x);
!     return std::pair<typename Base::iterator, bool>(Base::end(), true);
    }
  
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateEdge<MData, VData, EData, FData, false> *>::iterator find(SFTemplateEdge<MData, VData, EData, FData, false> *const &element) const
    {
!     return std::find(Base::begin(), Base::end(), element);
    }
  };
  
***************
*** 343,352 ****
    /// Inserts element x at the end of the std::vector. Is equivalent to push_back and provided to have common interface with std::map.
    std::pair<typename Base::iterator, bool> insert(const std::pair<unsigned int, SFTemplateFace<MData, VData, EData, FData, false> *> &x)
    {
!     if (x.first >= size())
        resize(x.first + 1, 0);
    
!     typename Base::iterator it = begin();
      it += x.first;
      *it = x.second;
      
--- 343,352 ----
    /// Inserts element x at the end of the std::vector. Is equivalent to push_back and provided to have common interface with std::map.
    std::pair<typename Base::iterator, bool> insert(const std::pair<unsigned int, SFTemplateFace<MData, VData, EData, FData, false> *> &x)
    {
!     if (x.first >= Base::size())
        resize(x.first + 1, 0);
    
!     typename Base::iterator it = Base::begin();
      it += x.first;
      *it = x.second;
      
***************
*** 356,367 ****
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateFace<MData, VData, EData, FData, false> *>::iterator find(SFTemplateFace<MData, VData, EData, FData, false> *const &element)
    {
!     return std::find(begin(), end(), element);
    }
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateFace<MData, VData, EData, FData, false> *>::const_iterator find(SFTemplateFace<MData, VData, EData, FData, false> *const &element) const
    {
!     return std::find(begin(), end(), element);
    }
  };
  
--- 356,367 ----
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateFace<MData, VData, EData, FData, false> *>::iterator find(SFTemplateFace<MData, VData, EData, FData, false> *const &element)
    {
!     return std::find(Base::begin(), Base::end(), element);
    }
    /// Finds the element. Is provided for having a common interface with std::set and std::map.
    typename std::vector<SFTemplateFace<MData, VData, EData, FData, false> *>::const_iterator find(SFTemplateFace<MData, VData, EData, FData, false> *const &element) const
    {
!     return std::find(Base::begin(), Base::end(), element);
    }
  };
  
